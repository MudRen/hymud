 // book.c
inherit ITEM; 
void create()
{
        int     i; 
        string *names = ({
                "���׾���", "��̫��ȭ�ס�", "��������ͼ��","��̫���ڹ����š�"
        }); 
        string *skills= ({
                "literate", "parry", "dodge", "force"
        }); 
        i = random(4);
        set_name( names[i], ({ "book" }));
        set_weight(100);
        set("value", 2000);
        set("unit", "��");
        set("long", "����һ�������䵱�������书���鼮��\n");
        set("skill", ([
                "name":                 skills[i],
                "exp_required": 0,                
                "jing_cost":     30,     
                "difficulty":   30,            
                "max_skill":    90           
                                            
        ]) );
        
} 
