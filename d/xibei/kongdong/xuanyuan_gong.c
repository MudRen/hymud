//1997-3-10 by qyz

inherit ROOM;

//string *things = ({
//            "/clone/misc/chabei",
//            "/clone/misc/chahu",
//            "/clone/misc/hongcha",
//            "/clone/misc/lvcha",
//          "/d/menpai/kongdong/obj/yaochi",
//            });


#include <room.h>


void create()
{
	set("short","��ԯ��");
	set("long",@LONG
�߽����ţ������Ǹߴ�Ĳ�ɫ����������Χ���������ʵ۾��м���ʱ�ù�
�ļ�����������ǰ�����һ����̨����̨�ϼ�������ų�΢���Ĺ�â��һ������
�����¯�������������������ɾ������������ж���Ϸ���˫�ﳯ��װ�Σ���
�ڹ����������ۣ���̤���ģ�������������������
LONG);
	set("exits",
	([
          "east" : __DIR__"18_yuan",
          "west" : __DIR__"yuhuang_ge",
          "south" : __DIR__"zhaohe_tang",
          "north" : __DIR__"lingzhi_yuan",
          	]));
      set("valid_startroom", "1");
    set("need_clean","�����");
	set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects" , ([
		__DIR__"npc/kdizi1" : 3 ,
		__DIR__"npc/mu" : 1 ,
		__DIR__"npc/song" : 1,
		__DIR__"npc/xia" : 1,
"/quest/menpai/newmp/shi11" : 1,
"/d/biwu/champion_kd" : 1,	
		]) );

    setup();
}
void reset()
{
	string s_obj;
	::reset(); 
	switch(random(5))
	{
	case 0:
		s_obj = __DIR__"obj/yaochi";
		break;
	case 1:
		s_obj = __DIR__"obj/book5";
		break;
	case 2:
		s_obj = __DIR__"obj/book1";
		break;	
	case 3:
		s_obj = __DIR__"obj/book4";
		break;						
	default:
		s_obj = __DIR__"obj/yaochi";
		break;
	}
	set("search_things", ([
		"��¯" :  s_obj,
		]) );
}