// Room: /d/pingan/pingankezhan
inherit ROOM;

void create ()
{
  set ("short", "�Ŵ��ջ");
  set ("long", @LONG
����ǹŴ�����������С��ջ��˵����������Ҳ����ֻ��СС�ļ���
���棬һ�������ĵ�С��վ�ڹ�̨ǰ�棬��Ц����ӭÿһ�������Ŀ��ˡ���
Ϊ�������û�иߵ͹�������˶��ǿ��Լ����Ͷ�������Ͷ��ǿɳܵ���
Ϊ������ǰ����һ��СС�����ƣ�paizi����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "���꼱�蹤����Ա������������С������[����]���¡�
",
]));

 set("roomif","$botten#����|�깤:ask xiao er about job|give panzi to xiao er$#");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chufang",
"west" : __DIR__"tingtang",
  "south" : __DIR__"fight",
]));
  set("pingan", 1);
  set("chatroom",1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("no_dazuo", 1);
  set("no_kill", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
