 // An example book
inherit ITEM; 
void create()
{
    set_name("�����������" , ({ "perception book","book" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ�������������֮�����ؼ���\n");
        set("value", 0);
        set("skill", ([
                "name":                 "perception",      
                "exp_required": 100000,       
                "jing_cost":             35,
                "difficulty":   30,  
                "max_skill":    50     
        ]) );
}
       
