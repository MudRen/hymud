// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������
ǰ����̨�ϰ���һ������(paizi)����̨���������ϰ壬һ˫������
�������´������㡣
    ¥���¿���С��ի��
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "��ƽ����

sell        �� 
buy         ��
redeem      ��
value       ����
",
]));

set("roomif","$botten#��|��|��|����|�鿴����|�鿴�鼮|�鿴����|�鿴����:sell <��Ʒ>|buy <��Ʒ>|redeem <��Ʒ>|value <��Ʒ>|list armor|list book|list misc|list weapon$#");

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tang" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"welcome",
  "east" : __DIR__"dangpu2",
]));
  set("no_beg", 1);
  set("no_fight", 1);
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}
