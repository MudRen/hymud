 inherit ITEM;
void create()
{
        set_name("����", ({ "mirror", "����"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("prep", "on");
                set("long", "һ����Ŀ�ľ��ӣ�����������Щ���֡�\n");
                set("value", 1);
                set("skill", ([
                        "name":         "kongshoudao",        
                        "exp_required": 100,              
                        "jing_cost":     100,     
                        "difficulty":   100,     
                        "max_skill":    100              
                ]) );
        }
    
} 
int is_container() { return 1; }     
