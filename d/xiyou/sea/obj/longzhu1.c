# include <skill.h>

inherit ITEM;

void create()
{
        set_name("������", ({"jin longzhu", "zhu", "pearl"}));
	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",0);
		set("unit","��");
		set("long",
"һ�Ŷ���Բ������飬��˵ֻ�еõ��������Ż��С�
���й�Ӱ�ζ����ƺ�����(touch)֮�»ᷢ����ʡ�
��������ƺ����а˹�֮�࣬Ҳ���ܺϲ�(combine)���������顣\n");
	}
	setup();
}
