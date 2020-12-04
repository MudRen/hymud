#include <ansi.h> 
#include <armor.h>

inherit HANDS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;31m��ͷ֮����[2;37;0m", ({ "good hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
��ͷ֮����[2;37;0m����һ�����ޱȼ�Ӳ�ľ��ּ���[33m����[2;37;0m�Ƴɣ���һ��������Ǯ��[1;31m��ͷ֮����[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m �������ޱȼ�̣�����[36mһ��[2;37;0m�ķ�������
���滹����һЩ���֣�
��Ӳ:[1;31m��Ԫ[2;37;0m ����:[34mϸ��[2;37;0m 
����:[36m����[2;37;0m 

LONG
);
		
		set("value", 9000);
		set("armor_prop/intelligence",2);
		set("armor_prop/strength",3);
		set("armor_prop/karey",4);
		set("armor_prop/percao",2);
		set("armor_prop/dexerity",2);
		set("armor_prop/constitution",2);
    set("armor_prop/dodge", 2);
    set("armor_prop/parry", 2);
    set("armor_prop/attack", 2);
set("makeritem",1);

    set("armor_prop/armor", 47);
    set("armor_prop/defense", 2);
    
    set("armor_prop/neili", 2);
    set("armor_prop/qi", 2);
    set("armor_prop/jing", 2);
    set("armor_prop/jingli", 2);
    set("armor_prop/damage", 199);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",3);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}





#include "/obj/ritem/armorzy.h";