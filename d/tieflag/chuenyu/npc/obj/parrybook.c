 // An example book
inherit ITEM; 
void create()
{
        set_name("����Ҫּ" , ({ "parrybook" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ�����ܲ���ж��֮����������\n");
        set("value", 0);
        set("skill", ([
                "name":                 "parry",      
                "exp_required": 2000,       
                "jing_cost":             15,
                "difficulty":   15,  
                "max_skill":    60     
        ]) );
       
}
  
