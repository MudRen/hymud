
inherit ROOM;
#include <room.h>
#include <ansi.h>



void create()
{
	set("short", YEL"����̨"NOR);
	set("long",@LONG
�������Ŷ���ľ�������Դ����ͭ�Ƶİ���̨��̨ͭ�Ͽ���һ���޴��
����ͼ���������ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢���ķ�λ
�Ų����Ŷ����ӿ�������������ռ�����ǳ����顣
LONG);
    set("need_clean", "�����");
	set("exits",
	([
             "down" : __DIR__"18_yuan",
          	]));
    setup();

}
