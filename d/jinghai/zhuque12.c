// zhuque12.c 
// by dicky

#include <ansi.h>
inherit ROOM;

void create()

{
	set("short", "��ͷľ��");
	set("long", @LONG
������һ����ľͷ���ɵ���ͷС�ݣ�С���������ҵĶѻ���
һЩ������С�ݵ����������ͷ����ͷ�߼�����Ҫ������������
Ⱥ��
LONG);

	set("exits", ([
	"east" : __DIR__"zhuque3",
		]));
	setup();
}

int init()
{
        add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
         object me;
         me = this_player();
         if( !arg || arg != "didao")
         return notify_fail("ʲô��\n");
	
        if( me->query("class") != "jinghai")
         return notify_fail("ʲô��\n");

         if ( arg =="didao")
        {
         write("�㲦�����ҵĶ�����ͻȻ������һ���ص�����Ѹ�ٵ����˽�ȥ��\n");
         message("vision",
         me->name() + "���㲻ע�⣬ͻȻ��ʧ��һС�ݵĽ������档\n",
                     environment(me), ({me}) );
         me->move(__DIR__"moon22");
         message("vision",
                  me->name() + "ͻȻ������С�����������������˺ܾã�ֻ����û�з��֣�\n",
                             environment(me), ({me}) );
          }
          return 1;

}
