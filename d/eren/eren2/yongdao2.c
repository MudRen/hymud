 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��");
        set("long",  @LONG
�����ɴ����£��ֶ�ת��֮������Խ��Խխ��������ʪ�����ĳ�������̦��
����Ҳ�����쳣��һ��С�ľͻ�ˤ�������ڶ�������ƺ���ú��ܵ���ÿ��ʮ��
�߱��������ĵ������ζ����ڶ��������³�����Ӱ�ӣ���֪�����ִ�������
���磬����ë���Ȼ��
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao3",
                "southup" : __DIR__"yongdao1",
                "east" : __DIR__"yongdao2a",
        ]));
        set("objects", ([
                __DIR__"npc/rat" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
