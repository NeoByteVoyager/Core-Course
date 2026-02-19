#include"User.h"

// 1. User 的构造函数实现
User::User(string acc, string pwd, int r) {
    account = acc;
    password = pwd;
    role = r;
}

// 2. 检查密码实现
bool User::checkPassword(string inputPwd) {
    return (password == inputPwd);
}

// 3. 获取账号,密码实现
string User::getAccount() {
    return account;
}
string User::getPassword() {
	return password; 
}
// 4. 获取角色实现
int User::getRole() {
    return role;
}

// 5. 修改密码实现
void User::setPassword(string newPwd) {
    password = newPwd;
}
