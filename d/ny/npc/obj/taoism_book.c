
// taoism_book.c

inherit ITEM;

void create()
{
        set_name("��ʦ��������", ({ "taoismbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"����һ����ʦ���������ţ�ֻ��ѧ����ʦ����������ܽ�һ�����éɽ���ĵȼ�.\n"
                );
                set("value", 12260);
                set("material", "paper");
                set("skill", ([
                        "name":     "taoism",    // name of the skill  
                    "exp_required": 500, // minimum combat experience equired 
                        "sen_cost":  30, // gin cost every time study this
                      "difficulty":  10,//the base int to learn this skill
        // modify is gin_cost's (difficulty - int)*5%
                    "max_skill":  20 // the maximum level you can learn
                                                                               
        // from this object.
                ]) );
        }
}
 
