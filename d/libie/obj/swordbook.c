 // An example book
inherit ITEM; 
void create()
{
        set_name("���ƽ���" , ({ "swordbook" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "һ����ȱ��ȫ�Ľ��ף���ߵ�һ���Ѿ����ٻ٣����ÿ����ʽ��ֻʣ��һ�롣\n");
        set("value", 0);
        set("skill", ([
                "name":                 "libie-sword",      
                "exp_required": 1500000,       
                "jing_cost":       50   ,
                "difficulty":  100,  
                "max_skill":    80     
        ]) );
        set("no_get",1);
        set("no_drop",1);
}
     
