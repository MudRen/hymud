// fangjian2.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�䲼�ó�����ģ����С���䣬����ʯ�������ϰ��Ÿ�СС��ľͷ
�Ƴɵ�ҡ����ǽ��������һ�������٣����߶��Ѿ����ˡ�
LONG );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));
       set("no_clean_up", 0);
       setup();
}

void init()
{
        add_action("do_shout", "shout");
        add_action("do_shout", "han");
}

int do_shout(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

if (me->query_temp("big5") && userp(me) && arg!="" ) arg=LANGUAGE_D->Big52GB(arg);

	if( arg=="֥�鿪��" || arg=="opendoor") 
	{
		tell_object(me,"�����˵������ǽ�ڴ��һ������֥�鿪�ţ���\n");

		message("vision", "����һ�������ֻ����һ���¡¡��������������һ�����š�\n", me);
		set("exits/down", __DIR__"shishi4");
		remove_call_out("close");
		call_out("close", 8, this_object());

	}
}

void close(object room)
{
	message("vision","һ���¡¡����������ʯ���ֻ����ع����ˡ�\n", room);
	room->delete("exits/down");
}
