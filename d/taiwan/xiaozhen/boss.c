// Room: /d/taiwan/boss.c

inherit ROOM;

void create()
{
	set("short", "�޴�ɽ��");
	set("long", @LONG
����ʯ������,��վ��һ���޴��ɽ����,̧ͷ����,��һ������ʯ 
һֱ���������ɵĸߴ�.�ڿ���һ�ߵ�ʯ����,�����������˼���̨��,̨ 
�׵ľ�ͷ��һ����ֵ�����.�Ա�������ľ���ϻ�������������. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southup" : __DIR__"shandong2",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "����" : "������������,ɭɭ�İ׹��ƺ���������Ц. 
",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/shenxiang.c" : 1,
  __DIR__"npc/hufa.c" : 1,
  __DIR__"npc/mentu.c" : 2,
]));

	setup();
}
void init()
{
 add_action("do_push","push");
}
int do_push(string arg)
{
  object ob;
  ob=this_player();
	if(!ob || environment(ob)!=this_object())	return notify_fail("
  ��Ҫ��ʲô����?\n");
  if (!arg||arg!="shenxiang") return notify_fail("
  ��Ҫ��ʲô����?\n");
  message_vision("$N�ƿ�����������ȥ.\n",ob);
  ob->move(__DIR__"mishi");
  return 1;
 }
