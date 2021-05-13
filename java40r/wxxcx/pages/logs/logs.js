const DB = wx.cloud.database().collection("userInfo")


Page({
  data: {
    username: '',
    password: '',
    userinsystem:[]
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    console.log(options)
    wx.getUserInfo({
      success: this.setUserInfo.bind(this)
    })
    this.setData({

    })
  },
  setUserInfo: function (res) {
    this.setData({
      user: res.userInfo
    })
  },

  create_login: function (e) {
    console.log(e.detail.value)
    this.setData({
      username: e.detail.value.username,
      password: e.detail.value.password
    })
    var that=this
    DB.where({
      input1:this.data.username
    }).get({
      success(res) {
        console.log('查询数据成功', res)
        console.log(res)
        that.setData({
          userinsystem:res.data
        })
      },
      fail(res) {
        console.log("查找数据失败", res)
      }
    })
    console.log("dddddddddddddddddd ",this.data.userinsystem)
  },
getResult: function (res) {
  console.log(res.data);
  if (res.data == "true") {
    wx.showToast({
      title: "登录成功",
      duration: 2000
    })
    wx.switchTab({
      url: '../index/index',
    })
    setTimeout(function () {
      wx.navigateBack({
        delta: 2
      })
    }, 1000)
  }

  if (res.data == "false") {
    wx.showToast({
      title: "账号或密码不对",
      icon: 'none',
      duration: 3000
    })
    setTimeout(function () {
      wx.navigateBack({
        delta: 2
      })
    }, 1000)
  }
},
goto_index: function (res) {
  wx.navigateTo({
    url: '../index/index',
  })
},
goto_zhuce: function (res) {
  wx.navigateTo({
    url: '../zhuce/zhuce',
  })
}
})