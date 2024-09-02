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
	/// <typeparam name="...Args">任意の引数の型</typeparam>
	/// <param name="...args">任意の数の引数</param>
	/// <returns>インスタンスのアドレス</returns>
	template <typename... Args>
	static T* GetInstance(Args&&... args) {
		if (!instance_) {
			Create(std::forward<Args>(args)...);
		}
		return instance_.get();
	}

private:
	/// <summary>
	/// インスタンスを作成
	/// </summary>
	/// <typeparam name="...Args">任意の引数の型</typeparam>
	/// <param name="...args">任意の数の引数</param>
	template <typename... Args>
	static void Create(Args&&... args) {
		instance_ = std::make_unique<T>(std::forward<Args>(args)...);
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
