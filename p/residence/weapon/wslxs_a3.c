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
	      set_name("[35mÇÜÌì[2;37;0m", ({ "yunti hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
[37mÔÆÌİÖ®ÊÖÌ×[2;37;0mÕâÊÇÒ»¸±ÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ïÆßÁ½¶şÇ®µÄ[37mÔÆÌİÖ®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [32mË®[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m¿ªÔª[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[32m´Ö²Ú[2;37;0m ÉÁµç:[36m²»´í[2;37;0m 
ÍşÁ¦:[34mÏ¸Ëé[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·ÉÏè[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÄÚ¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wslxs");
		set("ownername", "·ÉÏè");
		set("value", 16000);
		set("armor_prop/intelligence",35);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 35);
    set("armor_prop/parry", 31);
    set("armor_prop/attack", 17);


    set("armor_prop/armor", 162);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 771);

    set("wtypeA",0);
    set("wtypeB",8);
    set("wtypeC",4);
    set("wtypeD",11);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";