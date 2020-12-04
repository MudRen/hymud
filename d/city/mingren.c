// Room: /city/mingren.c
// YZC 1995/12/04 

#include <room.h>
#define BOARD_TOC "/doc/board/toc2"
#define BOARD_DIR "/doc/board/"
inherit ROOM;
string look_shu();

void create()
{
	set("short", "������");
	set("long", @LONG
�������������һ�ٵ������á������﹩����д�����Ҳ��ħͷ��
Ҳ�в��Ǵ�������ħͷ����ҡ���������һλ�������ھ�һʱ������
һ�����������Ķ��ǵĹ��£�ÿһ�����¶�������Զ��Ӱ����һ����
����������ҡ�
    ��Ȼ���Ƕ�����������������������ķ��꣬���������Ҳ��
���ڽ��������ˡ����Ƕ��Ѿ��˳������������ǵ���Ӱħ�ٺܳ�ʱ��
�Ժ�����һ����˵��

LONG );
set("chatroom",1);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"wumiao2",
	]));
	set("objects", ([
	]));
	setup();
	//replace_program(ROOM); 
}

void init()
{
        //add_action("do_read", "yuedu");
}

string look_shu()
{
        this_player()->start_more(read_file(BOARD_TOC));
        return "\n";
}

int do_read(string arg)
{
        object me=this_player();
        int line;
        if(!arg)
        return notify_fail("������Ҫ�����ļ�����ʼ�кš�(����˵yuedu book1.txt 0)\n");
        
        if(!sscanf(arg, "%s %d", arg,line))
        return notify_fail("������Ҫ�����ļ�����ʼ�кš�(����˵yuedu book1.txt 0)\n");
        
        if (arg == "" || file_size(BOARD_DIR + arg) <= 0)
                return notify_fail("����û����������Ү��\n");

        //log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
        //me->start_more(read_file(BOARD_DIR + arg));
        me->more("", explode(read_file(BOARD_DIR + arg), "\n"), line);
        return 1;
}

