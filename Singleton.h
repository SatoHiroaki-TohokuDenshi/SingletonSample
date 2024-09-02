#pragma once
#include <memory>

// 
// �Q�l�F
// https://qiita.com/kikuuuty/items/fcf5f7df2f0493c437dc
// 

/// <summary>
/// �V���O���g���Ƃ��ĊǗ����邽�߂̃N���X
/// </summary>
/// <typeparam name="T">�V���O���g���ŊǗ��������C�ӂ̃N���X</typeparam>
template <typename T>
class Singleton final {
public:
	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	/// <typeparam name="...Args">�C�ӂ̈����̌^</typeparam>
	/// <param name="...args">�C�ӂ̐��̈���</param>
	/// <returns>�C���X�^���X�̃A�h���X</returns>
	template <typename... Args>
	static T* GetInstance(Args&&... args) {
		if (!instance_) {
			Create(std::forward<Args>(args)...);
		}
		return instance_.get();
	}

private:
	/// <summary>
	/// �C���X�^���X���쐬
	/// </summary>
	/// <typeparam name="...Args">�C�ӂ̈����̌^</typeparam>
	/// <param name="...args">�C�ӂ̐��̈���</param>
	template <typename... Args>
	static void Create(Args&&... args) {
		instance_ = std::make_unique<T>(std::forward<Args>(args)...);
	}

	/// <summary>
	/// �C���X�^���X
	/// </summary>
	static std::unique_ptr<T> instance_;
};

/// <summary>
/// �C���X�^���X�̃O���[�o���錾
/// </summary>
/// <typeparam name="T">�V���O���g���ŊǗ��������C�ӂ̃N���X</typeparam>
template <typename T> std::unique_ptr<T> Singleton<T>::instance_;
