inherit ITEM;

void create()
{
        set_name("������", ({ "fisherbook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long",
                        "�Ȿ���ֽ�Ŷ��Ѿ������ˣ�ֻ��һЩ�ּ�ģ�����־䣬����\n"
                        "�ᵽһЩ��������֮��ķ���ʲ��ġ�\n");
                set("value", 800);
                set("material", "paper");
                set("skill", ([
                        "name":         "unarmed", 
                        "exp_required": 5000,    
                        "sen_cost":     20,      
                        "difficulty":   25,      
                        "max_skill":    91,   
                ]) );
        }
}

