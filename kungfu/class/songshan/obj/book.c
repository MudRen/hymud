 // book.c
inherit ITEM; 
void create()
{
    int i; 
   string *names = ({
        "���ط����㽣��", "��̩ɽʮ���̡�", "����ɽ������","����ǵ�����",
        "����ɽ������"
    }); 
    string *skills = ({
        "luoyan-jian", "shiba-pan", "songshan-jian", "liuhe-dao","hengshan-jian"
    });
        i = random(5);
    set_name( names[i], ({ "book" }));
    set_weight(100);
    set("unit", "��");
    set("long", "����һ�����������书���鼮��\n");
    set("skill", ([
        "name":                 skills[i],
        "exp_required": 0,                
        "jing_cost":             50,     
        "difficulty":   50,            
        "max_skill":    215           
                                            
        ]) );
        setup();
}    
