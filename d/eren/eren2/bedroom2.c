 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ���ţ����ŵ�һ��Ũ�һ��㣬���ڵ��������廨���棬ǽ�ϵ��ź���
������ᡡ��������á�������һ�����߿�,�˳߳��ĺ�ľ�ֽ�󴲣������ʯ
���������˾��ӣ��ݶ�����ʯ�̣�������Ů����֮ʽ��������Ѫ�����š�
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"palace4",
                                ]));
        set("objects", ([
                __DIR__"npc/girl2" : 1,
                __DIR__"npc/girl4" : 1,
                __DIR__"npc/xiaomimi" : 1,
                __DIR__"npc/baiyi" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
