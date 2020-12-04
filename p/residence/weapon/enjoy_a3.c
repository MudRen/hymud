#include <ansi.h> 
#include <armor.h>

inherit BOOTS;

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
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;31m�鲽[2;37;0m", ({ "bagua boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", @LONG
[1;37m�����С��ݡ����������ˡ����š�������������������������֮�𣬴��������򣬼����������һ��
[2;37;0m����һ˫���ޱȼ�Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ��ض���������Ǯ��[1;37m����֮ѥ[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;33m��ʥ[2;37;0m [32mˮ[2;37;0m:[1;31m��˫[2;37;0m [33m��[2;37;0m:[1;33m��ʥ[2;37;0m [1;35m��[2;37;0m:[1;34m����[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[35m��׼[2;37;0m 
��ʯ:[31m����[2;37;0m ����:[35m��׼[2;37;0m ����:[31m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m������[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "������");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 64);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 262);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 53);
    set("armor_prop/jing", 69);
    set("armor_prop/jingli", 69);
    set("armor_prop/damage", 113);

    set("wtypeA",10);
    set("wtypeB",6);
    set("wtypeC",12);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",8);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";