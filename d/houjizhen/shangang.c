// shangang.c 
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long", @LONG
�������ｼ���һ���س���˵�Ƿس�����ʵ��һ������ԣ���������һ��
�ƽ����˲��ٵ��ˣ���ʬ���������û����ȥ��ᣡ�������ǲŷ׷����⽨
��Щ�أ�����ȥ�������ǵ��԰�Ϣ����������ɱ��̫�أ����ﳣ�궼��������
��ģ������ĺ������洵�������Ե���ɭ�ɲ���ƽʱ��û�˸ҵ�������ֻ����
�ϵ���ѻ��ѽ��ѽ����ҵؽ��š�
LONG
	);
	set("exits", ([
	"northwest" : __DIR__"tomb",
	"east" : __DIR__"shulin3",
	]));
	setup();
//	replace_program(ROOM);
}



