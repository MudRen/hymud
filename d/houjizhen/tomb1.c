// tomb.c 
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","Ĺ��");
	set("long", @LONG
����һ���ܴ��Ĺ�ң��������Ų����ˡ�ǽ�Ϲ����˻�棬�յù�
�����ġ�ԭ�������ؤ��ĵ����ܶ棬һȺ��ؤΧ�ŵ�ͼ���ƺ����ڼ�
�ҵ�������ʲô��ǽ�Ǵ�����һ�ڿݾ�(well)��
LONG
	);

        set("outdoors", "houjizhen");

	set("valid_startroom",1);
	set("item_desc",([
	"well" : "��������ɵģ���֪ͨ�����\n",
	]));
	set("objects",([
		__DIR__"npc/dizi1" : 1,
		__DIR__"npc/dizi2" : 1,
	]));
//        call_other("/clone/board/gb_board2", "???");
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
       	object me;
        me = this_player();

        if( arg=="well" )     {
        message("vision",
	me->name() + "���������һ������һ���ۣ�������������ȥ��\n",environment(me), ({me}) );          		me->move(__DIR__"shangang");
        message("vision",me->name() + "�ӷ�Ĺ��ð�˳�����\n",environment(me), ({me}) );
        return 1;       
}
}
