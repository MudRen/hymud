// С�� /d/menpai/shennong/xiaodao3.c
// by lala, 1998-01-26

inherit ROOM;



void create()
{	
    set("short",    "С��");
	set("long",@LONG
һ������������С����·��������ŸߵĲݵء�Ҫ�ǲ����濴�����治����
������������������ɽ�����壬���������ɵĽ�������������������ɽ��ɽ֮��
�ڡ�·Խ��Խխ������þ�û�������ˡ�
LONG    );
    set("exits",    ([
        "northeast" :   __DIR__"dongfeng_di",
	    "west"      :   __DIR__"xiaodao4"  
    ]) );
    set("outdoors", "wuliang");
    setup();
}
