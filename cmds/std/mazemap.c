// mazemap.c

#include <ansi.h>
inherit F_CLEAN_UP;
    object get_object(string name) 
    { 
            object ob; 
            
            if (ob = find_object(name)) 
                    return ob; 
                     
           sscanf(name, "%s#%*s", name);  
            return load_object(name); 
     } 
int main(object me, string arg)
{ 
        object mazeobj;
        
        if (me->is_busy())
                return notify_fail("��������æ��\n");

        if (! wizardp(me) && (time() - me->query_temp("maze/map") < 3))
                return notify_fail("ϵͳ�������̾���������� ....\n");  
        
        if (! environment(me)->query("maze"))
                return notify_fail("���ﲻ���Թ��������� help here �鿴��\n");  
     
             if (! environment(me)->query("mazeobj"))
                return notify_fail("���ﲻ���Թ��������� help here �鿴��\n");  
     
                
        if (me->query("jing") < 5)
                return notify_fail("�����ھ���״̬���ѣ����ǵȻ��ٲ�ɡ�\n");
        
        mazeobj = get_object(environment(me)->query("mazeobj")); 

        me->add("jing", -5);
        me->set_temp("maze/map", time());
        
        if (wizardp(me) )
                write(mazeobj->display_deep_map(environment(me)));
        else
                write(mazeobj->display_common_map(environment(me)));
        return 1;
}