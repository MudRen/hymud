 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
һ�����ӣ�����������������������Ҳ����˿��������û������
�Ķ�������͸�����ڵĹ���ȴ����ʹ�㿴�帽����������������
��������Ȼ�Ļ����ϼ��˹����ɵģ�������ڰ�������һ�У���ʲô
���������ˡ�
LONG
        );
        set("exits", ([ 
          "north" : __DIR__"midao2",
          "west" : "/d/laowu/street4"
        ]));
        set("coor/x",100);
        set("coor/y",12050);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
