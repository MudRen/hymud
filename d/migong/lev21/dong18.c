
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
	set("long", RED @LONG
�����ǻ�����Թ�,�ƺ����������ѵĵط���Ȼ����
�ϵ�����һ�ѶѵĹǺ���Ǭ����Ѫ���������˾�������
�Ե�ʮ�ֵĹ��졣�ߴ����ľ��ס�����⣬��ʲôҲ�������ˡ�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_use", "use");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire",me)) return 0;
        if( arg=="fire" ) {
        remove_call_out("close");
        call_out("close", 15, this_object());
        message("vision","�ڻ���£��㿴����Χ�������!!\n", me);
        set("long", @LONG
�����ǻ�����Թ�,�ƺ����������ѵĵط���Ȼ����
�ϵ�����һ�ѶѵĹǺ���Ǭ����Ѫ���������˾�������
�Ե�ʮ�ֵĹ��졣�ڻ�����㿴���˳�·��
LONG
        );
	set("exits", ([
                "west" : __DIR__"dong1"+(random(5)+5),
		"east" : __DIR__"dong1"+(random(3)+7),
		"south" : __DIR__"dong1"+(random(5)+5),
                "north" : __DIR__"dong1"+(random(5)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong19",
                "north" : __DIR__"dong1"+(random(3)+7),
	]));
if (random(3)==1)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(3)+7),
                "west" : __DIR__"dong1"+(random(9)+1),
	]));




           if ( objectp(ob=present("fire", this_player())) )     {
            destruct(ob);
        return 1;
       }
        return notify_fail("������ʲô�������\n");
        }
}

void close(object room)
{
        message("vision","��һ�������Ϩ���ˡ�\n", room);
        set("long", @LONG
�����ǻ�����Թ�,�ƺ����������ѵĵط���Ȼ����
�ϵ�����һ�ѶѵĹǺ���Ǭ����Ѫ���������˾�������
�Ե�ʮ�ֵĹ��졣
LONG
);
        room->delete("exits");
}