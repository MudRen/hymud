// lbook1.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"������ˮ��"NOR, ({ "shenshui book", "book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("treasure",1);set("unit", "��");
                set("long","������ˮ����\n");
                set("value", 2000);
                set("material", "paper");
if (random(2)==0)
{
                set("skill",
                ([
                        "name": "nine-moon-claw",      // name of the skill
                        "exp_required": 10,      // minimum combat experience required
                        "jing_cost":    10,      // jing cost every time study this
                        "difficulty":   15,      // the base int to learn this skill
                        "max_skill":    149,      // the maximum level you can learn
                        "min_skill":    0,      // minimun level required
                ]) );
}
else
{
                set("skill",
                ([
                        "name": "nine-moon-sword",      // name of the skill
                        "exp_required": 10,      // minimum combat experience required
                        "jing_cost":    10,      // jing cost every time study this
                        "difficulty":   15,      // the base int to learn this skill
                        "max_skill":    149,      // the maximum level you can learn
                        "min_skill":    0,      // minimun level required
                ]) );
}



        }
}
