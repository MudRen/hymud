//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","ʯ��");
	set("long",@LONG
����ʯϿ�������վ��쳣��������һ��ǰ������·���ʵĶ����ϣ��ľ���Ѫ
�����±��ϼ�Ӳ�ޱȵ�ʯͷ���ɵ�һ����ʯ�ף�ʯ�׵���������һ�ÿ�ʯ������
������һ��������۵������������Ǿ�ֻ����������������������ʯ�����¡���
������ʫ̾Ү����һ���һ��������������������˼��У��ŵ�����·�����ɼ�
��ɽ֮�ա�
LONG);
	set("exits",
	([
          "southdown" : __DIR__"shijie1",
          "westup" : __DIR__"shangtian_ti",
	]));
        set("outdoors","kongdong");
        setup();
        //place_program(ROOM);
}
