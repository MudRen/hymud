 inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
���Խ����Խ������ֵ��ǣ����沢û�и�������������Խ��Խ��Ţ��
����������̦���������д���������ˣ�ˮ��Ҳ��Ũ�ˡ��Ѿ�û����
��𣬵�ԶԶ���ƺ���Щ���⣬Ҳ����ھ�Ҫ���ˣ�
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"exit1",
                "northup" : __DIR__"exit3",
                        ]));
        set("objects", ([
                __DIR__"npc/guardb" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
