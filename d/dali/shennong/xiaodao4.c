// С�� /d/menpai/shennong/xiaodao4.c
// By lala, 1998-01-26

inherit ROOM;



void create()
{
    set("short",    "С��");
    set("long",@LONG
һ������������С����·��������ŸߵĲݵء�Ҫ�ǲ����濴�����治����
������������������ɽ�����壬���������ɵĽ�������Զ��ϡ���ɢ�ż�Ƭũ�
��Ϊ����λ���������Ի�û���ܵ�������ս����Ӱ�졣
LONG
    );
    set("exits",    ([
        "east"      :   __DIR__"xiaodao3",
    	"southwest" :   "/d/dali/wuliang/lsdui",
    ]) );
    set("outdoors", "wuliang");
    setup();
}
