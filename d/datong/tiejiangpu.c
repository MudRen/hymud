// Room: /open/dt/tiejiangpu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ���ţ�һ�󡰶����������Ĵ������㲻���ڶ����������
Լ��ʮ������ƣ��е��������䣬�еİ��յ�ͨ������������
ռ�ϲ�ͣ���ô������������񣬺������͡���һ������תͷһ
����ֻ��������ʦ��������ǯ������һ�齣�κ�����ˮ����г�
���ַŵ���¯��������ǳ��������ӣ������Ǹ������ܳ��ء�
�ſڹ���һ��������(pai)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hongchanglu5",
]));

        set("item_desc", ([ /* sizeof() == 2 */
	"pai" :  "
�չ���������
����(fix)����
��Կ��(pei key)\n
",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
