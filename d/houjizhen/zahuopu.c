// zahuopu.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��ר��һЩ������Ʒ��С���̣���Ȼ�Ա߲�Զ������
���ջ�����������ë�����ӡ�����֮����ճ���Ʒȴ������
�����������￿����ɽ��Զ����������Ҳ���˲Ρ���ҩһ��Ľ�
���˳��õ���Ʒ��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"shilu2",
	]));

	set("objects",([
	__DIR__"npc/yang" : 1,
	]));

	setup();
	replace_program(ROOM);
}
