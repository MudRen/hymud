#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","�ٵ�");
  set("long",@LONG
����ƽ̹�Ĵ����ֱ��ͨ�򿪷⣬����ʮ���ɣ�·���ϵĻ���ѹ�ý��ʵʵ
������۹�Ҳֻ�����𳾰������������Ÿߴ�Ĵ�������һ�Ӷ����ó����ڴ��
����β������������ͷ���������ﲻ����̸�·��θ��죻�ٽ����⣬·��Խ����
���������������Ҳ�����˺ܶ��з������С������������ڶ���
LONG HIY @TEXT
    ������ʮ���⣬����Ǻ�ΰ�������ǽ�������ڵ�ƽ�ߴ���
TEXT NOR);
  set("exits",([
    "northeast" : "/d/kaifeng/yanqing",
    "west"  : __DIR__"guandao11",
    "east"  : __DIR__"yunhe0",	
  ]));
    set("outdoors","zhongyuan");
  setup();
}
