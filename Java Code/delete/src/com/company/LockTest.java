package com.company;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockTest {
    static class IncrementData {
        public static int sum = 0;

        public static void lockAndFastIncrease(Lock lock) {
            lock.lock();
            try {
                sum++;
            } finally {
                lock.unlock();
            }
        }
    }

    public static void testReentrantLock() {
        final int TURNS = 10000000;
        final int THREADS = 10;
        ExecutorService pool = Executors.newFixedThreadPool(THREADS);
        Lock lock = new ReentrantLock();
        CountDownLatch countDownLatch = new CountDownLatch(THREADS);
        long start = System.currentTimeMillis();
        for (int i = 0; i < THREADS; i++) {
            pool.submit(() -> {
                try {
                    for (int j = 0; j < TURNS; j++) {
                        IncrementData.lockAndFastIncrease(lock);
                    }
                    System.out.println("thread done!");
                } catch (Exception e) {
                    e.printStackTrace();
                }
                countDownLatch.countDown();
            });
        }
        try {
            countDownLatch.await();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(System.currentTimeMillis() - start);
        System.out.println("IncrementData.sum = " + IncrementData.sum);
    }

    public static void main(String[] args) {
        LockTest.testReentrantLock();
    }
}
