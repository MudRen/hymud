 // TIE@FY3 ALL RIGHTS RESERVED
//XXDER
inherit ROOM;
void create()
{
        object con,item;
        set("short", "��������");
        set("long", @LONG
����һƬ�ȵأ������֮�У��ƺ�֮�󣬾�Ȼ��һ���˹�����ĵ�ɽ·��
������ʯ�̾ͣ�������Է��򻬣���Ϊ���£��Լ��õ�������֮ʱ��������
����������Ѫ��
LONG
        );
        set("outdoors","shenshui");
        set("exits", ([ 
  "southwest" : __DIR__"gudi",
  "northup" : __DIR__"tianti2",
]));
        set("objects", ([
                __DIR__"obj/rock" : 1,
                __DIR__"npc/qinggirl" : 2,
        ]) );
        set("outdoors","shenshui");
        set("coor/x",160);
        set("coor/y",12220);
        set("coor/z",10);
        setup();
        con = present("rock",this_object());

}    
