// Room: /open/dt/hejiqianzhuang.c

inherit BANK;

void create()
{
	set("short", "�ͼ�Ǯׯ");
	set("long", @LONG
�ͼ�Ǯׯ�Ǵ�ͬ����������ơ����ֺ��ˣ�������֧���Ľ�
����ɫ�ر�ĺã�����Ҳ���㡣���Һͼ���ȫ������������ﶼ
�����ţ�������������˾Ͳ��ô��ű��صĽ����������ˡ���̨
����һ������(sign)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huaandao1",
]));

        set("item_desc", ([ /* sizeof() == 2 */
	"sign" :  "�ͼ�ǮׯĿǰ�ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan		ת��
",
]));

	set("objects",([
	__DIR__"npc/he" : 1,
]));

	setup();
}
