 inherit ITEM;
void create()
{
        set_name("���㸡Ӱ", ({ "book", "anxiang steps", "anxiang" }));
        set_weight(600);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long",
                    "�鱾��ҳ���������ʹ�����һ��ѩ��ʢ���ĺ�÷��\n");
            set("value", 0);
            set("no_give", 1);
            set("no_drop", 1);
            set("no_sell",1);
            set("material", "paper");
/*          set("skill", ([
                    "name": "anxiang-steps",
                    "exp_required": 5000,
                    "sen_cost": 60,
                    "difficulty": 35,
                    "max_skill": 135,
            })); */
        }
}     
