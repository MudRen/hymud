 // book.c
inherit ITEM; 
void create()
{
        set_name( "ռ������", ({ "book" }));
        set_weight(100);
        set("value", 2000);
        set("unit", "��");
        set("long", "����һ������ռ��ѧ���鼮��\n");
        set("skill", ([
                "name":                 "literate",
                "exp_required":         0,                
                "jing_cost":             30,     
                "difficulty":           30,            
                "max_skill":            30           
                                            
        ]) );
        
}
