 inherit ROOM;
void create()
{
        set("short", "ׯ�ڵ�");
        set("long", @LONG
����һ��ո��ո�����������ɢ�����ܶ��������һ������
���������У���ȴ�Ų�����Χߴߴ��������ȸ�����ǲ�ͣ�ط��Ϸ��£�
������ɢ�ڵ���������
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"farm7",
        ]));
        set("objects", ([ 
                __DIR__"npc/bird" : 2,
                __DIR__"npc/dahan" : 1,
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",80);
        set("coor/y",-70);
        set("coor/z",0);
        setup();
replace_program(ROOM); 
}     
