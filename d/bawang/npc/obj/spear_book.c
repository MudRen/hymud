 // An example book
inherit ITEM; 
void create()
{
        set_name("����ǹ��" , ({ "spear book","book"}) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ������ǹ����ү���������Ļ���ǹ����\n");
        set("value", 500);
        set("no_get", 1);
        set("no_give", 1);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_burn", 1);
        set("skill", ([
                "name":                 "club",      
                "exp_required": 1000000,       
                "jing_cost":             20,
                "difficulty":   15,  
                "max_skill":   200     
        ]) );
        
}
    
