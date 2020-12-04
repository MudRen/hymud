//room: jian.c

inherit ROOM;

void init();
int do_zou(string);

void create()
{
  set("short","���հ��ɽ�");
  set("long",@LONG
ɽ������ͻȻ��ʧ��������ǰ��һ��ɽ����ɽ��֮���������ƣ����
���޷�������档һ������(tiesuo)�������У��Ա���һ��ʯ��(bei)��
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "enter" : "/d/llszhuang/road",
      "southdown" : __DIR__"yan",
  ]));
  
	set("roomif","$botten#��Ԯ����|��Ʒ����|ɽ������|ȡ����Ԯ|����ɽ��:ask yu about job|ask yu about work|ask yu about job3|ask yu about ʧ��|shouwei$#");	  
  
  set("objects",([
      "quest/menpaijob/lingjiu/yupopo" : 1,
  ]));
  set("item_desc",([
      "bei" : "�����չ����صأ�����������\n" ,
      "tiesuo" : "����ͨ������ġ������š�����Ҳ������߹�(zou)ȥ��\n" ,
  ]));
//  set("no_clean_up", 0);
  setup();
}

void init()
{
	add_action("do_zou", "zou");
}

int do_zou(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="tiesuo")
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' \n");
	message_vision("$N����������ƮȻ��ȥ��\n",me);
//       ��message("vision","��ֻ��һ����ӰƮȻ������\n", room);
        me->move(room);
        return 1;
}
