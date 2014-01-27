
//==============================================================================
// ファイル名	: Joh-Mon.h
// 概要			: Joh-Monプログラム全体に共通して使用されるデータの定義を記述し
// 				  たファイル。
// 最終更新日	: 2014/01/20
// 更新者		: Yanagimachi Tenshi
// Encoding		: UTF-8
//==============================================================================



/*******************************************************************************
 * インクルードガード
 ******************************************************************************/
#ifndef JOH-MON_H
#define JOH-MON_H



/*******************************************************************************
 * 定数定義
 ******************************************************************************/
#define STRING_SIZE	256	// 文字列を扱う際の許容最大文字数
#define PLAYER_NUM	2	// 対戦プレイヤ数
#define TYPE_NUM	3	// パーツタイプの数
#define PARTS_NUM	10	// パーツの個数



/*******************************************************************************
 * 構造体定義
 ******************************************************************************/
struct Command {
	char name[STRING_SIZE];	// コマンド名
	int id;					// コマンドID
};

struct Parts {
	char name[STRING_SIZE];	// パーツ名
	int id;					// パーツID
	int type;				// パーツタイプ
	int paramater;			// パラメータ(攻撃力)
};

struct Monster {
	char name[STRING_SIZE];			// モンスター名
	struct Parts parts[TYPE_NUM];	// 構成パーツ
	int hp;							// 残り体力
};

struct Player {
	char name[STRING_SIZE];	// プレイヤ名
	struct Monster monster;	// 所持モンスター
	int selectCommand;		// 選択したコマンド
};

struct World {
	struct Player player[PLAYER_NUM];		// 対戦する各プレイヤ
	struct Command command[TYPE_NUM];		// 使用できるコマンド
	struct Parts parts[PARTS_NUM];			// 使用できるパーツ
	int priorityMatrix[TYPE_NUM][TYPE_NUM];	// コマンドの優位判定表
};



/*******************************************************************************
 * インクルードガード
 ******************************************************************************/
#endif	// #ifndef JOH-MON_H