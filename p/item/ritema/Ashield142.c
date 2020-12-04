#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[34mµ§Íñ÷Æ∂‹[2;37;0m", ({ "general shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "√Ê");
		set("long", @LONG
µ§Íñ÷Æ∂‹[2;37;0m’‚ «“ª√Ê”…œ‡µ±º·”≤µƒæ´∏÷º”…œ[33m—«¬È[2;37;0m÷∆≥…£¨÷ÿ“ªΩÔæ≈¡Ω∆ﬂ«Æµƒ[34mµ§Íñ÷Æ∂‹[2;37;0m°£
◊€∫œ∆¿º€[31mÕÍ√¿æ´÷¬[2;37;0m ø¥∆¿¥œ‡µ±º·πÃ£¨æﬂ”–[34m≤ª¥Ì[2;37;0mµƒ∑¿ª§¡¶£°
…œ√ÊøÃ¡Àº∏∏ˆπ≈∑˚∫≈£∫
[1;33mΩ[2;37;0m:[32m¥÷≤⁄[2;37;0m [1;35m∑Á[2;37;0m:[1;34mæŸ ¿[2;37;0m 

…œ√ÊªπøÃ¡À“ª–©∑˚◊÷£∫
º·”≤:[33m∫‹∏ﬂ[2;37;0m «…÷∆:[36m≤ª¥Ì[2;37;0m 
ÃÂ¡È:[34mœ∏ÀÈ[2;37;0m ◊œ Ø:[34mœ∏ÀÈ[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 21);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 127);
    set("armor_prop/defense", 20);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",3);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",8);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 4);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";