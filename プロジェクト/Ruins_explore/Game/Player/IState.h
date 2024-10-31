/*
	@file	IState.h
	@brief	ステートのインターフェース
*/
#pragma once

class IState
{
public:
	virtual ~IState() = default;
	// 初期化する
	virtual void Initialize() = 0;
	// 更新する
	virtual void Update(const float& elapsedTime) = 0;
	// 描画する
	virtual void Render() = 0;
	// 後処理を行う
	virtual void Finalize() = 0;
};
