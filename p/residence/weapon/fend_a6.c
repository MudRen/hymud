#include <ansi.h> 
#include <armor.h>

inherit HEAD;

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
	      set_name("[1;33mÇ¬À¤Ö®Í·¿ø[2;37;0m", ({ "qiankun head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
		set("long", @LONG
[1;33m´ËÎï×óÓÒÁ½±ß·Ö±ğÒÔºÚ°×Á½ÖÖÆæÌúÈÜÖı¶ø³É£¬Ò»ºÚÒ»°×£¬ÇĞºÏÇ¬À¤£¬°üº¬ÒõÑôÖ®Æø£¬ºÃÒ»±ú±¦Îï£¡
[2;37;0mÕâÊÇÒ»¶¥ÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÒ»½ï¾ÅÁ½ÁùÇ®µÄ[1;33mÇ¬À¤Ö®Í·¿ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[31m¾«ÖÂ[2;37;0m [31m»ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;31m¿ªÔª[2;37;0m 
[1;37mÀ×[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÌìÓî:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[35m±ê×¼[2;37;0m 
°×Ê¯:[35m±ê×¼[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
³¤Éú:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·½·½[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fend");
		set("ownername", "·½·½");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 58);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 45);


    set("armor_prop/armor", 467);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 30);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 267);

    set("wtypeA",6);
    set("wtypeB",6);
    set("wtypeC",6);
    set("wtypeD",11);
    set("wtypeE",0);
    set("wtypeF",13);
    set("wtypeG",10);
    set("wtypeH",6);
    set("wtypeI",5);
    set("wtypeJ",6);
    set("wtypeK",5);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "strike",
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