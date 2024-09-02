#pragma once
#include <memory>

// 
// 参考：
// https://qiita.com/kikuuuty/items/fcf5f7df2f0493c437dc
// 

/// <summary>
/// シングルトンとして管理するためのクラス
/// </summary>
/// <typeparam name="T">シングルトンで管理したい任意のクラス</typeparam>
template <typename T>
class Singleton final {
public:
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>インスタンスのアドレス</returns>
	static T* GetInstance() {
		if (!instance_) {
			Create();
		}
		return instance_.get();
	}

private:
	/// <summary>
	/// インスタンスを作成
	/// </summary>
	static void Create() {
		instance_ = std::make_unique<T>();
	}

	/// <summary>
	/// インスタンス
	/// </summary>
	static std::unique_ptr<T> instance_;
};

/// <summary>
/// インスタンスのグローバル宣言
/// </summary>
/// <typeparam name="T">シングルトンで管理したい任意のクラス</typeparam>
template <typename T> std::unique_ptr<T> Singleton<T>::instance_;
