// shanya.c
// by dicky

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "ɽ����");
  set ("long", @LONG
ǰ����һ���߷壬��ɽ�������������ƣ����к�⡣����ɽ��Ƚ�
���ͣ��������￴������һ���ͱڣ��ͱ��϶�����̦��𣬿���ȥ�쳣
�Ļ��֡�ɽ�����к������󣬿�ɽ��������������˵�������õ�ʱ��
��������ɽ�����˵�Х�����˶���Ϊ�����������档������������ʿ˵
��˵�е�̤ѩɽׯ�������⸽����
LONG);

	set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 3 */
		"eastdown" :  __DIR__"qiaobi",
	]));

	setup();
}



