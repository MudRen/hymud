// Room: /d/jinghai/moon22.c

inherit ROOM;

void create()
{
	set("short", "����é��");
	set("long", @LONG
����һ���úܶ�����������é�ݴ���ɵļ�ª��é�ݡ�����
ֻ��һ���ƾɵ�ľ����һ��С�����Ÿ��崦�����š����ڴ�ɨ��
�ܸɾ������������������ﳤס�����ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
 "east" : __DIR__"moon1",
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
         write("�����봲�ף�ͻȻ������һ���ص�����Ѹ�ٵ����˽�ȥ��\n");
         message("vision",
         me->name() + "���㲻ע�⣬ͻȻ���봲�ף���ʧ�����ˣ�\n",
                     environment(me), ({me}) );
         me->move(__DIR__"zhuque12");
         message("vision",
                  me->name() + "ͻȻ��������������������ϵĻҳ���վ��������\n",
                             environment(me), ({me}) );
          }
          return 1;

}

