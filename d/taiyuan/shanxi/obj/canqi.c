 inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"����"NOR, ({ "����","canqi" }));
                 set("long",
"��Ȼ����������һ���о֣�����ϸ��Ħ����������������������а�����ƺ��ܴ��������һЩ����\n"
               );  
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 70);
                set("material", "wood");
                set("no_shown",1);
                set("no_get",1);
                set("no_drop",1);
                set("skill", ([
                        "name":                 "finger",    
                        "exp_required": 0,              
                        //"sen_cost":             0,     
                        "difficulty":   100,     
                        "max_skill":    100              
                ]) );
        }
    
} 
