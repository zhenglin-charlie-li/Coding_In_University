package com.lzl.dao;

import com.lzl.model.User;

public interface IUserDao {

    User selectUser(long id);
}