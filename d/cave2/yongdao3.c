 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��");
        set("long", @LONG
����������΢ƽ̹һЩ�����϶��˼�յ�͵ơ����϶��˼����
ʯ����ͨ���ѵ�ֻ��һ�˿��Բ���������ʯ��վ�ż�������ɫ��
�����ˣ���������Ӱ֮�С�
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao4",
                "southup" : __DIR__"yongdao2",
                "westup" : __DIR__"yongdao3a",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}   
