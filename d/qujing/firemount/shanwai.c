// created by snowcat on 4/11/1997
// room: shanwai

inherit ROOM;

int check_move(object me, string arg);

void create ()
{
  set ("short", "ɽ��С·");
  set ("long", @LONG

��ͻȻ���˻���ɽ�������棬�������Ǻ�ͨͨ�Ļ���ɽ����������
��һ��ǿ�ҵĺ�ζ���ȵ������������ܡ�������һ��С����ͨ��ɽ
����������

LONG);

  set("exits", ([
        "northdown"  : __DIR__"hongyan",
        "southeast"  : __DIR__"huoyan",
     ]));
  set("outdoors", "xy21");

  setup();
}

void init()
{
add_action("do_look", "look");
}

int do_look(string arg)
{
if (arg=="southeast") {
	if (this_player()->query("obstacle/firemount")=="done")
		set("exits/southeast", __DIR__"nofire");
	else set("exits/southeast", __DIR__"huoyan");
	}
return this_player()->force_me("look "+arg);
}

int valid_leave(object me, string dir)
{
  if ( dir=="southeast" ) {
	if (me->query("obstacle/firemount")!="done") {
		set("exits/southeast", __DIR__"huoyan");
		me->set_temp("burnt_in_mount",0);
		me->set_temp("fanned_in_mount",0);
		me->set_temp("fan_times_in_mount",0);
		}
	else {
		set("exits/southeast", __DIR__"nofire");
		}
	return ::valid_leave(me, dir);
	// mon 4/11/98 modified this to prevent Illegal move error.
	}
return ::valid_leave(me, dir);
}




